#include <bits/stdc++.h>
using namespace std;

int N, color[100005];
long long ans[100005];
vector<int> v[100005];

// current sum, (color, count), (count, color)
pair< map<int, int> *, map<int, long long> * >  dfs(int x, int par) {
    if (v[x].size() - (par != -1) == 0) {
        map<int, int> *s1 = new map<int, int>();
        map<int, long long> *m1 = new map<int, long long>();
        (*s1)[color[x]] = 1;
        (*m1)[1] += color[x];
        ans[x] = color[x];
        return make_pair(s1, m1);
    }
    map<int, int> *s1 = new map<int, int>();
    map<int, long long> *m1 = new map<int, long long>();
    (*s1)[color[x]] = 1;
    (*m1)[1] += color[x];
    map<int, int> *s = s1;
    map<int, long long> *m = m1;
    for (int i = 0; i < v[x].size(); i++) {
        if (v[x][i] == par) continue;
        pair< map<int, int>*, map<int, long long>* > res = dfs(v[x][i], x);
        if (s->size() < res.first->size()) {
            swap(s, res.first);
            swap(m, res.second);
        }
        //printf("%d\n", res.first->size());
        for (map<int, int>::iterator it = res.first->begin(); it != res.first->end(); it++) {
            int c = it->first, cnt = it->second;
            if (s->find(c) == s->end()) {
                (*m)[cnt] += c;
                (*s)[c] += cnt;
            } else {
                (*m)[(*s)[c]] -= c;
                if ((*m)[(*s)[c]] == 0) m->erase((*s)[c]);
                (*s)[c] += cnt;
                (*m)[(*s)[c]] += c;
            }
        }
        //printf("meow\n");
    }
    ans[x] = m->rbegin()->second;
    //printf("return %d\n", x);
    return make_pair(s, m);
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) scanf("%d", &color[i]);
    for (int i = 0; i < N-1; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        v[x-1].push_back(y-1);
        v[y-1].push_back(x-1);
    }
    dfs(0, -1);
    for (int i = 0; i < N; i++) {
        if (i) printf(" ");
        printf("%lld", ans[i]);
    }
    printf("\n");
}
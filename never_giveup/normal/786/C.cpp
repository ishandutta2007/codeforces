#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#ifdef ONPC
const int maxn = 100, inf = 1e9 + 100, sq = 2;
#else
const int maxn = 1e5 + 100, inf = 1e9 + 100, sq = 500;
#endif
int n, a[maxn], answer[maxn];

int q[maxn / sq + 10][maxn];

int cnt[maxn / sq + 10], siz;

int st[maxn / sq + 10], fin[maxn / sq + 10];

int vis[maxn];

int sz;

void add(int x){
    vis[x]++;
    if (vis[x] == 1)
        sz++;
}

void rem(int x){
    vis[x]--;
    if (vis[x] == 0)
        sz--;
}

void add(int x, int id){
    q[id][x]++;
    if (q[id][x] == 1)
        cnt[id]++;
}

void rem(int x, int id){
    q[id][x]--;
    if (q[id][x] == 0)
        cnt[id]--;
}

int main(){
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #else
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i], a[i]--;
    for (int i = 1; i <= min(n, sq); i++){
        answer[i] = 1;
        int last = 0;
        for (int j = 0; j < n; j++){
            add(a[j]);
            if (sz > i){
                for (int k = last; k < j; k++)
                    rem(a[k]);
                answer[i]++;
                last = j;
            }
        }
        for (int j = last; j < n; j++)
            rem(a[j]);
    }
    int know = sq + 1;
    answer[know] = 1;
    int last = 0;
    for (int j = 0; j < n; j++){
        add(a[j]);
        add(a[j], siz);
        if (sz > know){
            rem(a[j], siz);
            st[siz] = last;
            fin[siz] = j - 1;
            siz++;
            for (int k = last; k < j; k++)
                rem(a[k]);
            add(a[j], siz);
            answer[know]++;
            last = j;
        }
    }
    st[siz] = last;
    fin[siz] = n - 1;
    siz++;
    for (int k = sq + 2; k <= n; k++){
        for (int i = 0; i < siz; i++){
            int id;
            if (i == 0)
                id = -1;
            else
                id = fin[i - 1];
            if (id == n - 1){
                siz = i;
                break;
            }
            while (fin[i] <= id)
                fin[i]++, add(a[fin[i]], i);
            while (st[i] <= id)
                rem(a[st[i]], i), st[i]++;
            while (fin[i] < n - 1){
                fin[i]++;
                add(a[fin[i]], i);
                if (cnt[i] > k){
                    rem(a[fin[i]], i), fin[i]--;
                    break;
                }
            }
        }
        answer[k] = siz;
    }
    for (int i = 1; i <= n; i++)
        cout << answer[i] << ' ';
}
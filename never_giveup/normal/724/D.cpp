#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 1e5 + 100;

int m, n;

string s;

set<int> q;

string answer;

vector<int> pos[26];

int main(){
    //ifstream cin("a.in");
    //ofstream cout("a.out");
    ios::sync_with_stdio(0);
    cin >> m >> s;
    n = s.length();
    for (int i = 0; i < n; i++)
        pos[s[i] - 'a'].push_back(i);
    q.insert(-1);
    q.insert(n);
    for (int it = 0; it < 26; it++){
        int cnt = 0;
        for (int i = 0; i < pos[it].size(); i++){
            set<int> :: iterator a, b;
            b = q.lower_bound(pos[it][i]);
            a = q.lower_bound(pos[it][i]);
            a--;
            if (*b - *a - 1 < m)
                continue;
            if (i != (int)pos[it].size() - 1 && pos[it][i + 1] < *b && pos[it][i + 1] <= *a + m)
                continue;
            else
                cnt++, q.insert(pos[it][i]);
        }
        bool is = 1;
        int last;
        for (set<int> :: iterator i = q.begin(); i != q.end(); i++){
            if (i == q.begin()){
                last = *i;
                continue;
            }
            if (*i - last - 1 >= m){
                is = 0;
                break;
            }
            last = *i;
        }
        if (is){
            for (int i = 0; i < cnt; i++)
                answer.push_back('a' + it);
            break;
        }
        else
            for (int i = 0; i < pos[it].size(); i++)
                answer.push_back('a' + it), q.insert(pos[it][i]);
    }
    cout << answer;
}
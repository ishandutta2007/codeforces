#include "bits/stdc++.h"
using namespace std;
const int N = 1e4 + 4;
const int L = 1e3 + 3;
const int SN = 1e6 + 6;
const int M = 1e5 + 5;
int n;
string str;
int m;
string arr[M];
int dp[N];
int nxt[N];
int sz[SN];
int en[SN];
int child[SN][26];
int cur = 0;
char print[N];
void insert(int idx){
    string tmp = arr[idx];
    reverse(tmp.begin() , tmp.end());
    int node = 0;
    for(char c : tmp){
        ++sz[node];
        int nxt = tolower(c) - 'a';
        if(!child[node][nxt]){
            child[node][nxt] = ++cur;
        }
        node = child[node][nxt];
    }
    en[node] = idx;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> str;
    str = " " + str;
    cin >> m;
    for(int i = 1 ; i <= m ; ++i){
        cin >> arr[i];
        insert(i);
    }
    dp[n + 1] = 1;
    for(int i = n ; i >= 1 ; --i){
        dp[i] = 0;
        int node = 0;
        int cur = i;
        while(cur <= n){
            int nxtt = tolower(str[cur]) - 'a';
            if(!child[node][nxtt]){
                break;
            }
            node = child[node][nxtt];
            ++cur;
            if(en[node]){
                if(dp[cur]){
                    dp[i] = 1;
                    nxt[i] = en[node];
                    break;
                }
            }
        }
    }
    cur = 1;
    while(cur <= n){
        cout << arr[nxt[cur]] << " ";
        cur += int(arr[nxt[cur]].size());
    }
}
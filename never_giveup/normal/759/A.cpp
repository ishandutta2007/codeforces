#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 2e5 + 100;

int n;

int p[maxn];

int b[maxn];

bool vis[maxn];

int main(){
    #ifndef ONPC
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    #else
    ifstream cin("a.in");
    ofstream cout("a.out");
    #endif
    ios::sync_with_stdio(0);
    int answer = 0;
    int cnt = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i], p[i]--;
    int tmp = 0;
    for (int i = 0; i < n; i++)
        cin >> b[i], tmp += b[i];
    for (int i = 0; i < n; i++)
    if (!vis[i]){
        int x = i;
        bool is = 0;
        while (!vis[x]){
            vis[x] = 1;
            x = p[x];
        }
        cnt++;
    }
    if (cnt > 1)
        answer += cnt;
    if (tmp % 2 == 0)
        answer++;
    cout << answer;
}
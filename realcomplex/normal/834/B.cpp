#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    cin >> n >> k;
    int vis[n];
    char s;
    int last[26];
    for(int x = 0;x<26;x++){
        last[x] = -1;
    }
    int fi[26];
    for(int i = 0;i<26;i++){
        fi[i] = -1;
    }
    for(int i = 0;i<n;i++){
        cin >> s;
        vis[i] = s-65;
        last[vis[i]] = i;
        if(fi[vis[i]] == -1){
            fi[vis[i]] = i;
        }
    }
    int open = 0;
    bool is = false;
    for(int x = 0;x<n;x++){
        if(fi[vis[x]] == x){
            open++;
        }
        if(open > k){
            is = true;
        }
        if(last[vis[x]] == x){
            open--;
        }
    }
    if(is == true){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
    return 0;
}
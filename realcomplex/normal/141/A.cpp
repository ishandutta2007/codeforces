#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define fi first
#define se second

int a[26],s[26];

int main(){

    string ai,bi,ci;
    cin >> ai >> bi >> ci;
    for(int i = 0;i<ai.size();i++){
        a[ai[i]-64]++;
    }
    for(int i = 0;i<bi.size();i++){
        a[bi[i]-64]++;
    }
    for(int i = 0;i<ci.size();i++){
        s[ci[i]-64]++;
    }
    bool can = true;
    for(int i = 0;i<26;i++){
        if(a[i] != s[i]){
            can = false;
        }
    }
    if(can == true) puts("YES");
    else puts("NO");
    return 0;
}
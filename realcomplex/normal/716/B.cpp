#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e12

void open(){
    freopen("in.txt","r",stdin);
    //freopen("01.out","w",stdout);
}

main(){
    //open();
    string s;
    cin >> s;
    int n = s.size();
    bool is = false;
    int p;
    for(int i = 0;i<=n-26;i++){
        vector<int>cnt(26,0);
        is = true;
        for(int x = i;x<i+26;x++){
            if(s[x] != '?'){
                cnt[s[x]-65]++;
            }
        }
        for(int j = 0;j<26;j++){
            if(cnt[j]>1){
                is = false;
                break;
            }
        }
        if(is == true){
            p = 0;
            while(cnt[p]!=0)p++;
            for(int x = i;x<i+26;x++){
                if(s[x] == '?'){
                    s[x] = p+65;
                    cnt[p]++;
                }
                while(cnt[p]!=0){
                    p++;
                }
            }
            for(int x = 0;x<n;x++){
                if(s[x] == '?') s[x] = 'A';
            }
            cout << s;
            exit(0);
        }
    }
    cout << -1;
    return 0;
}
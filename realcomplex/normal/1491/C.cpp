#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);


int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        int n;
        cin >> n;
        vector<ll> s(n);
        vector<int> rig(n+1);
        rig[n]=-1;
        ll outp = 0;
        for(int i = 0 ; i < n; i ++ ){
            cin >> s[i];
        }
        rig[n]=n;
        for(int i = n-1; i >= 0 ; i -- ){
            if(s[i] == 1) rig[i]=rig[i+1];
            else rig[i]=i;
        }
        int pp;
        int nx;
        int sw;
        for(int i = 0; i < n; i ++ ){
            if(i == n - 1){
                outp += (s[i] - 1);
                break;
            }
            else{
                if(i + s[i] >= n){
                    outp += (i + s[i] - n + 1);
                    s[i] = n - 1 - i;
                }
                while(s[i] > 1){
                    pp = i;
                    outp ++ ;
                    while(pp < n){
                        if(s[pp] == 1){
                            pp = rig[pp];
                        }
                        else{
                            nx = pp+s[pp];
                            if(s[pp] == 2){
                                sw = pp;
                                rig[sw]=rig[sw+1];
                                for(int j = sw - 1; j >= 0 ; j -- ){
                                    if(s[j] == 1) rig[j]=rig[j+1];
                                    else break;
                                }
                            }
                            s[pp]=max(1ll,s[pp]-1);
                            pp=nx;
                        }
                    }
                }
            }

        }
        cout << outp << "\n";
    }
    return 0;
}
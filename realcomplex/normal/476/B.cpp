#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e10
#define fi first
#define se second
#define mp make_pair
#define MAXN 100005

int main(){

    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string a,b;
    cin >> a >> b;
    int l = 0;
    for(int j = 0;j<a.size();j++){
        if(a[j]=='+')l++;
        else l--;
    }
    int u = 0;
    int cnt = 0;
    for(int j = 0;j<b.size();j++){
        if(b[j] == '+'){
            u++;
        }
        else if(b[j] == '-'){
            u--;
        }
        else{
            cnt++;
        }
    }
    double fir,sec;
    fir = 0;
    sec = 0;
    int tek;
    for(int x = 0;x<(1<<cnt);x++){
        tek = u;
        for(int i = 0;i<cnt;i++){
            if(x&(1<<i)){
                tek++;
            }
            else{
                tek--;
            }
        }
        if(tek==l){
            fir++;
        }
        sec++;
    }
    fir/=sec;
    cout << fixed << setprecision(10) << fir;
    return 0;
}
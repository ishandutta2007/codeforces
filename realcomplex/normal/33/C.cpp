#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e18

void open(){
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
}

int main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int k[n+1];
    k[0] = 0;
    int cl,cr;
    int l,r;
    l = 0;
    r = 0;
    cl = 0;
    cr = 0;
    int s = 0;
    int p = 0;
    for(int j = 1;j<=n;j++){
        cin >> k[j];
        if(s+k[j]>k[j]){
            cr++;
            s += k[j];
        }
        else{
            cl = j;
            cr = j;
            s = k[j];
        }
        if(s>p){
            p = s;
            l = cl;
            r = cr;
        }
    }
    for(int i = 0;i<l;i++){
        k[i]*=-1;
    }
    for(int j = r+1;j<=n;j++){
        k[j]*=-1;
    }
    int rez = 0;
    for(int j = 1;j<=n;j++){
        rez += k[j];
    }
    cout << rez;
    return 0;
}
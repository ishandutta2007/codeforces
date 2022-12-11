#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e9

void open(){
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
}

bool check(string a,string b){
    return a.size()>b.size();
}



int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    n*=2;
    int v[200];
    for(int j = 1;j<=n;j++){
        cin >> v[j];
    }
    sort(v+1,v+n+1);
    int fl;
    int sum;
    int rez = INT_MAX;
    for(int j = 1;j<=n;j++){
        for(int x = j+1;x<=n;x++){
            fl = -1;
            sum = 0;
            for(int i = 1;i<=n;i++){
                if((i!=j) && i!=x){
                    sum += fl*v[i];
                    fl = -fl;
                }
            }
            rez = min(rez,sum);
        }
    }
    cout << rez;
    return 0;
}
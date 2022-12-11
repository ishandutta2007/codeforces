#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e18

void open(){
    freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}

int cnt[100005];
bitset<100005>k;

int rez = 1;

void siev(){
    k[1] = 1;
    for(int j = 2;j<100005;j++){
        if(k[j] == 0){
            int tek = cnt[j];
            int p = j*2;
            while(p<100005){
                tek += cnt[p];
                k[p] = 1;
                p+=j;
            }
            rez = max(tek,rez);
        }
    }
}

int main(){
    //open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int sk;
    for(int i = 0;i<n;i++){
        cin >> sk;
        cnt[sk]++;
    }
    siev();
    cout << rez;
    return 0;
}
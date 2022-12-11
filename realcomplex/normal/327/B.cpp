#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define INF 1e12

void open(){
    freopen("in.txt","r",stdin);
    //freopen("output.txt","w",stdout);
}

bitset<10000005>pir;

void sieve(){
    pir[2] = 0;
    int p;
    for(int j = 2;j<10000005;j++){
        if(pir[j] == 0){
            p = j*2;
            while(p<10000005){
                pir[p] = 1;
                p+=j;
            }
        }
    }
}

main(){
    //open();
    sieve();
    int n;
    cin >> n;
    int p = 0;
    for(int i = 2;i<10000005;i++){
        if(pir[i] == 0){
            cout << i << " ";
            p++;
            if(p == n) exit(0);
        }
    }
    return 0;
}
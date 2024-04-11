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
   // open();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    int a = 0,b = 0;
    int sa = 0,sb = 0;
    int pb = n-1;
    int bars[n];
    for(int j = 0;j<n;j++) cin >> bars[j];
    for(int i = 0;i<=pb;i++){
        sa += bars[i];
        a++;
        while(sb<sa&&pb>i){
            sb += bars[pb];
            pb--;
            b++;
        }
    }
    cout << a << " " << b;
    return 0;
}
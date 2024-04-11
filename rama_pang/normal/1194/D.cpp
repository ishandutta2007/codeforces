#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
using namespace std;

ll N,M,R,C,arr[100],K;

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    // for (ll i=0; i<=30; i++){
    //     ll k=0;
    //     if (i-1>=0) k|= (arr[i-1]^1);
    //     if (i-2>=0) k|= (arr[i-2]^1);
    //     if (i-8>=0) k|= (arr[i-8]^1);
    //     arr[i]=k;
    //     cout << i << " " << k << endl;
    // }
    ll T; cin>>T;
    while (T--){
        cin >> N >> K;
        if (K%3!=0){
            if (N%3==0){
                cout << "Bob\n";
            } else{
                cout << "Alice\n";
            }
            continue;
        }
        if ((N+1)%(K+1)==0 or (((N+1)%(K+1))%3!=1)){
            cout << "Alice\n";
        } else{
            cout << "Bob\n";
        }
    }
}
/*
0=B
1=A
2=A
3=B
4=A
5=A
6=B
1=yang ambil turn menang
0=kalah
I= (I-1 ^1)|(I-2 ^1)|(I-K ^1)


 */
#include <bits/stdc++.h>
using namespace std;

long long int solve(long long int n, long long int x){
    if(n==1) return 1;
    else if(n%2==1){
        if(x==1) return 1;
        else if(x==2) return solve(n-1, n-1) + 1;
        else return solve(n-1, x-2) + 1;

    }

    else{
        if(x%2==1) return x/2+1;
        else return solve(n/2, x/2) + n/2;
    }
}

int main(){
   long long int n, q;
   cin >> n >> q;

   long long int x[q];
   for(int i=0; i<q; i++){
        cin >> x[i];
    cout << solve(n, x[i]) << endl;
   }
}
#include <bits/stdc++.h>
using namespace std;

int main(){
   int n, k;
   cin >> n >> k;
   vector<int> a;
   int skap=0;

   for(int i=0; i<k-1; i++){
        for(int j=2; j<n+1; j++){
            if(n%j==0){
                n/=j;
                a.push_back(j);
                break;

            }


        }

        if(n==1){
            skap=1;
            break;
        }
   }

   if(skap==1) cout << "-1";
   else{
        for(int i=0; i<a.size(); i++){
            cout << a[i] << " ";
        }
        cout << n;
   }
}
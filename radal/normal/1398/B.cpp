 #include <bits/stdc++.h>
 #define ll long long int
   #define rep(i,l,r) for (ll i=l; i<r; i++)
   #define repr(i,r,l) for (ll i=r; i>=l; i--)
   #define endl '\n'
   using namespace std;
   int main(){
       ll t;
       cin >> t;
      rep (j,0,t){
          string n;
          cin >> n;
          vector <ll> ve;
          rep (i,0,n.size()){
              if (n[i] == '1'){
                  ll T=0;
                  while (i<n.size() && n[i] == '1'){
                     T++;
                      i++;
           //           cout << i << " " << n.size() << endl;
                 }
                  ve.push_back(T);
              }
          }
          sort(ve.begin(),ve.end());
          ll ans=0;
          bool f=1;
          //cout << ve.size() << " dadf" <<endl;
          if (ve.empty()){
            cout << 0 << endl;
            continue;
          }
          repr (i,ve.size()-1,0){
                  if (f){
                      ans+=ve[i];
                  }
                  f = !f;
          }
          cout << ans << endl;
      }
  }
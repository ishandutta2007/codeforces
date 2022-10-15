//279C

    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL)
    #define modLim (int)(pow(10,9)+7)
     
    int main(){
         fastIO;
        int n,m; cin >> n >> m;
        int A[n]; for(int i=0;i<n;i++) cin >> A[i];
        
        int inc[n],dec[n]; 
        for(int i=0;i<n;i++){
            inc[i] = 1;
            dec[i] = 1;
        }
        // cout << "hello" << endl;
        for(int i=n-2;i>=0;i--){
            if(A[i]<=A[i+1]) inc[i] = inc[i+1] + 1;
            if(A[i]>=A[i+1]) dec[i] = dec[i+1] + 1;
        }
        // for(int i=0;i<n;i++) cout << inc[i] << " " ;cout << endl;
        // for(int i=0;i<n;i++) cout << dec[i] << " " ;cout << endl;
        
        for(int i=0;i<m;i++){
            int l,r; cin >> l >> r;
            l--;r--;
            if(dec[l+inc[l]-1] + l+inc[l]-2 >= r) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
     
        return 0;
    }
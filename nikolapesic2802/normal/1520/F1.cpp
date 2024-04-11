#include<bits/stdc++.h>
 
typedef long long ll;
using namespace std;
 
//Modern computers do around 1e8 operations per first
// (m(m+1)/2)%Mod = ((m/2)%Mod) * ((m+1)%Mod))%Mod ----> Only if m is even
 
int main(){
    
    int n, t;
    cin >> n >> t ;
    int k;
    cin >> k;
    
    
    int l = 1;
    int r = n;
    int mid;
    int temp = 0;
    
    if(n == 0)
    {
        cout << 0 << endl;
    }
    
    while(l != r)
    {
mid = (l+r)/2;
        cout << "? " << l << " " << mid << endl;
        fflush(stdout);
        //cout << endl;
        //cout.flush();
        int noOnes;
        cin >> noOnes;
        //int noOfZeros = (r-l+1) - noOnes + temp;
        int noOfZeros = (mid-l+1 - noOnes + temp);
        
        
        //cout << " 0 " << noOfZeros << endl;
        
        if(noOfZeros >= k)
        {
            r = mid;
        } else
        {
            temp = noOfZeros;
            l = mid+1;
        }
    }
    
    cout << "! " << l << endl;
    
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, mini;
    mini=1000000;
    cin >> n >> m;
    
    int subarray[m][2];
    for(int i=0; i<m; i++){
        cin >> subarray[i][0] >> subarray[i][1];    
    }
  
    for(int i=0; i<m; i++) {
        if(subarray[i][1]-subarray[i][0]<mini) mini=subarray[i][1]-subarray[i][0];
               
    }
    
    cout << mini+1 << endl;
    
    for(int i=0; i<n; i++){
     cout << i%(mini+1) << " ";   
    }
}
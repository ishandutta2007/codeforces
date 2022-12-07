#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    int n,m;
    long long int k;
    
    cin>>n>>m;
    cin>>k;
    
    if(k<n)
    {
        cout<<k+1<<" 1"<<endl;
    }
    else
    {
        k = k-n;
        int row = n - (k/(m-1));
        k = k% (m-1);
        if(row%2==0)
        {
            cout<<row<<" "<<k+2<<endl;
        }
        else
        {
            cout<<row<<" "<<m-k<<endl;
        }
    }
    return 0;
}
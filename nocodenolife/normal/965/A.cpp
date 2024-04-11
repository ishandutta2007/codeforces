#include <bits/stdc++.h>
using namespace std;


int main() {
    
    int k,n,s,p;

    cin>>k>>n>>s>>p;
    int sheet = (n+s-1)/s;
    int sheets = sheet*k;
    int packs = (sheets+p-1)/p;
    
    cout<<packs<<endl;

    return 0;
}
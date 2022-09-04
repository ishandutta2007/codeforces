#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    //ifstream cin("in.txt");
    //ofstream cout("out.txt");
    int n,t,r,q[1000],ans=0;
    cin>>n>>t>>r;
    for(int i=0;i<1000;i++){
        q[i]=0;
    }
    if(t<r){
        cout<<-1;
        return 0;
    }
    for(int k=0;k<n;k++){
        int w;
        cin>>w;
        w--;
        int ko=q[w];
        for(int i=0;i<max(0,r-ko);i++){
            ans++;
            for(int j=max(w-i,0);j<w-i+t;j++){
                q[j]++;
            }
        }
    }
    cout<<ans;
}
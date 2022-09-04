#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main()
{
    //ifstream cin("in.txt");
    //ofstream cout("out.txt");
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        if(i%2==1)
            for(int j=0;j<m;j++)
                cout<<'#';
        else
        if(i%4==2){
            for(int j=0;j<m-1;j++)
                cout<<'.';
            cout<<'#';
        }
        else{
            cout<<'#';
            for(int j=0;j<m-1;j++)
                cout<<'.';
        }
        cout<<'\n';
    }
}
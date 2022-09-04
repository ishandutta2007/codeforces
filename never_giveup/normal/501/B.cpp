#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
vector< vector<string> > q;
int main()
{
    int n;
    cin>>n;
    string a,b;
    for(int it=0;it<n;it++){
        cin>>a>>b;
        int f=-1;
        for(int i=0;i<q.size() && f==-1;i++){
            if(q[i][q[i].size()-1]==a){
                f=i;
            }
        }
        if(f==-1){
           vector<string> p;
           p.push_back(a);
           p.push_back(b);
           q.push_back(p);
        }
        else{
            q[f].push_back(b);
        }
    }
    cout<<q.size()<<endl;
    for(int i=0;i<q.size();i++){
        cout<<q[i][0]<<" "<<q[i][q[i].size()-1]<<'\n';
    }
}
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    string n;
    cin>>n;
    int pearl=0, dash=0;
    for(int i=0;i<n.length();i++)
    {
        if(n[i] == 'o')
            pearl++;
    }
    dash = n.length()-pearl;
    if(dash==0||pearl==0)
        cout<<"YES";
    else
    {
        if(dash%pearl==0)
            cout<<"YES";
        else
            cout<<"NO";
    }
    
    return 0;
}
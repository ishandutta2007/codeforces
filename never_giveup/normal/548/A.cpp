#include <bits/stdc++.h>

using namespace std;

int main()
{
    //ifstream cin("in.txt");
    //ofstream cout("out.txt");
    string s;
    int k;
    cin>>s>>k;
    if(s.length()%k!=0){
        cout<<"NO";
        return 0;
    }
    k=s.length()/k;
    for(int i=0;i<s.length();i+=k){
        for(int j=i;j<i+k/2;j++)
        if(s[j]!=s[i+k-1-j+i]){
            cout<<"NO";
            return 0;
        }
    }
    cout<<"YES";
}
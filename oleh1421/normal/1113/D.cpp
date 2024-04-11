#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
string t;
bool ok(string s){
    string s1=s;
    reverse(s.begin(),s.end());
    return (s1==s && s!=t);
}
int main()
{
    cin>>t;
    string cur="";
    for (int i=1;i<(int)t.size();i++){
        string s1="";
        string s2="";
        for (int j=0;j<i;j++) s1+=t[j];
        for (int j=i;j<(int)t.size();j++) s2+=t[j];
        if (ok(s2+s1)){
            cout<<1;
            return 0;
        }
    }
    string s1="";
    string s2="";
    int i=0;
    int j=(int)t.size()-1;
    while (i<j){
        s1+=t[i];
        s2=t[j]+s2;
        if (s1!=s2){
            cout<<2;
            return 0;
        }
        i++;
        j--;
    }
    cout<<"Impossible";
    return 0;
}
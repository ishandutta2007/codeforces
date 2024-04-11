#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<string,int> dict;
    for(int i=0,k=0;i<26;i++)
        for(int j=0;j<26;j++)
        {
            if(i==j)continue;
            string word;
            word+='a'+i;
            word+='a'+j;
            dict[word]=++k;
        }
    int T;
    cin>>T;
    while(T--)
    {
        string word;
        cin>>word;
        cout<<dict[word]<<endl;
    }
    return 0;
}
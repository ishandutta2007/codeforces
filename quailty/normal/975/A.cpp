#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    set<string> str;
    for(int i=1;i<=n;i++)
    {
        string word;
        cin>>word;
        sort(word.begin(),word.end());
        word.erase(unique(word.begin(),word.end()),word.end());
        str.insert(word);
    }
    cout<<str.size()<<endl;
    return 0;
}
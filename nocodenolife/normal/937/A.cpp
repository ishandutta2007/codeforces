#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        arr.push_back(a);
    }
    
    sort(arr.begin(),arr.end());
    vector<int>::iterator ip;
    ip = unique(arr.begin(),arr.end());
    arr.resize(std::distance(arr.begin(), ip));
    if(arr[0]==0)
    {
        int answer = arr.size() -1;
        cout<<answer;
    }
    else
    {
        int answer = arr.size();
        cout<<answer;
    }
    return 0;
}
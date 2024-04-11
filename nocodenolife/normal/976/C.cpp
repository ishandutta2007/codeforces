#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include<bits/stdc++.h>

using namespace std;

struct point
{
       int left;
       int right;
       int location;
};
typedef struct point Point;
    
bool waytosort(Point a , Point b);

int main() {
    int n;
    cin>>n;
    
    Point arr[n];
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin>>l>>r;
        arr[i].left = l;
        arr[i].right = r;
        arr[i].location = i+1;
    }
    
    sort(arr, arr+n, waytosort);
    
    int prevl = arr[0].right;
    for(int i=1;i<n;i++)
    {
        int curl = arr[i].right;
        if(curl<=prevl)
        {
            n=-1;
            cout<<arr[i].location<<" "<<arr[i-1].location<<endl;
            break;
        }
        prevl = curl;
    }
    if(n!=-1)
        cout<<"-1 -1"<<endl;
    return 0;
}

bool waytosort(Point a , Point b)
{
    if(a.left<b.left)
        return true;
    else if(a.left>b.left)
        return false;
    else
        return (a.right>b.right);
}
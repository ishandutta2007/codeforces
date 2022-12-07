#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

struct elem {
    int element;
    int value;
};

bool waytosort(struct elem one, struct elem two)
{
    return one.element< two.element;
}

int main() {
    int n;
    cin>>n;
    struct elem a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i].element>>a[i].value;
    }
    
    int m;
    cin>>m;
    struct elem b[m];
    for(int i=0;i<m;i++)
    {
        cin>>b[i].element>>b[i].value;
    }

    sort(a, a+n, waytosort);
    sort(b, b+m, waytosort);

    int i=0,j=0;
    long long answer=0;
    while(i<n&&j<m)
    {
        if(a[i].element == b[j].element)
        {
            if(a[i].value>b[j].value)
                answer+=a[i].value;
            else
                answer+=b[j].value;
            j++;
            i++;
        }
        else if(a[i].element > b[j].element)
        {
            answer+= b[j].value;
            j++;
        }
        else
        {
            answer+= a[i].value;
            i++;
        }

    }
    while(i<n)
    {
        answer+=a[i].value;
        i++;
    }
    while(j<m)
    {
        answer+=b[j].value;
        j++;
    }

    cout<<answer<<endl;
    
    return 0;
}
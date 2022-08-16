#include <bits/stdc++.h>
using namespace std;

int A(int i,int j)
{
    cout << "AND " << i + 1 << ' ' << j + 1 << endl;
    cin >> i;
    return i;
}

int O(int i,int j)
{
    cout << "OR " << i + 1 << ' ' << j + 1 << endl;
    cin >> i;
    return i;
}

int X(int i,int j)
{
    cout << "XOR " << i + 1 << ' ' << j + 1 << endl;
    cin >> i;
    return i;
}

const int N = 1e6;
int n;
int arr[N];
int xorr[N];
int xor2[N];

signed main()
{
    cin >> n;
    
    for(int i=1;i<n;i++) xorr[i] = X(i-1,i);
    
    xor2[0] = 0;
    for(int i=1;i<n;i++) xor2[i] = xorr[i]^xor2[i-1];
    
    vector<int> same(n,-1);
    
    int fnd = -1;
    
    for(int i=0;i<n;i++)
    {
        if(same[xor2[i]] == -1) same[xor2[i]] = i;
        else
        {
            arr[i] = O(i,same[xor2[i]]);
            fnd = i;
            break;
        }
    }
    
    if(fnd != -1)
    {
        for(int i=fnd+1;i<n;i++)
            arr[i] = arr[i-1]^xorr[i];
        
        for(int i=fnd-1;i>=0;i--)
            arr[i] = arr[i+1]^xorr[i+1];
    }
    else
    {
        //all elements are distinct
        //same[0] and same[n-1] no xor -> all ones are there
        //AND it with a[1] to get a[1]
        assert(same[0] == 0);
        
        if(same[n-1] != 1)
        {
            
        arr[1] = O(same[0],1) & O(same[n-1],1);
        arr[0] = arr[1]^xorr[1];
        
        for(int i=2;i<n;i++)
            arr[i] = arr[i-1]^xorr[i];
            
        }
        else
        {
            arr[2] = O(same[0],2) & O(same[n-1],2);
            arr[1] = arr[2]^xorr[2];
            arr[0] = arr[1]^xorr[1];
            for(int i=3;i<n;i++)
                arr[i] = arr[i-1]^xorr[i];
        }
    }
    
    cout <<"! ";
    for(int i=0;i<n;i++) cout << arr[i] << ' ';
    cout << endl;
}
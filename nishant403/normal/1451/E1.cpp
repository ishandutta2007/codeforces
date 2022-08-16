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
int arr[N];

int go(int x)
{
    if(x == 1) return 1;
    return 1 + go(x/2);
}

signed main()
{
    int n;
    cin >> n;
    
    int bt = go(n);
    
    int a1 = O(0,1);
    int a2 = A(0,1);
    int a3 = A(1,2);
    int a4 = O(0,2);
    int a5 = O(1,2);
    
    for(int i=0;i<bt;i++)
    {
        if(a2 & (1LL<<i)) 
            arr[0] |= (1LL<<i) , arr[1] |= (1LL<<i);
        else if(!(a1 & (1LL<<i))) ;
        else
        {
            if(a3 & (1LL<<i))
                arr[1] |= (1LL<<i);
            else if(!(a5 & (1LL<<i)))
                arr[0] |= (1LL<<i);
            else if(a4 & (1LL<<i))
                arr[0] |= (1LL<<i);
            else 
                arr[1] |= (1LL<<i);
        }
    }
    
    //determine 2nd again
    for(int i=0;i<bt;i++)
    {
        if(a3 & (1LL<<i)) 
            arr[2] |= (1LL<<i);
        else if(!(a5 & (1LL<<i))) ;
        else if(arr[1] & (1LL<<i)) ; 
        else arr[2] |= (1LL<<i);
    }
    
    //0 and 1 are completely determined now 
    
    for(int i=3;i<n;i++)
        arr[i] = arr[i-1]^X(i-1,i);
    
    cout <<"! ";
    for(int i=0;i<n;i++) cout << arr[i] << ' ';
    cout << endl;
}
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include<iomanip>
using namespace std;
bool isprime (int n)
{
    if(n==1)
        return false;
    if (n==2)
        return true;
    if (n==3)
        return true;
    if(n%2==0)
        return false;
    if(n%3==0)
        return false;
    int i=5,w=2;
    while(i*i<=n)
    {
        if(n%i==0)
            return false;
        i+=w;
        w = 6-w;
    }
    return true;
}

int getPrev(int n)
{
    int primefac=1,i;
    for(i=2;i*i<n;i++)
    {
        if(n%i==0)
        {
            if(isprime(i)&&i>primefac)
                primefac=i;
            if(isprime(n/i)&&n/i>primefac)
                primefac=n/i;
        }
    }
    if(i*i==n)
    {
        if(isprime(i)&&i>primefac)
            primefac=i;
    }
    return n-primefac+1;
}

int main(){
    int x2;
    cin>>x2;
    int min = getPrev(x2);
    int answer = x2;
    for(;min<x2;min++)
    {
        if(getPrev(min)<answer)
            answer = getPrev(min);
    }
    cout<<answer<<endl;
    return 0;
}
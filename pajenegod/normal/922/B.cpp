
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    unsigned int n;
    cin >> n;
    vector<unsigned int> A(2*n+1);
    A[0] = 0;
    for (int i = 0; i<(2*n+1);++i)
    {
        int m = 1;
        while (m<=i) m*=2;
        m /= 2;
        A[i]=m;
    }
    int pairs = 0;
    for (unsigned int a = 1; a<(n+1); ++a)
    {
        for (unsigned int b = A[a]*2; b<(n+1); ++b)
        {
            unsigned int dum = a^b;
            int upp = min(a+b,n+1);
            for (unsigned int c = b; c<upp; ++c)
            {   
                if ((dum^c)==0) ++pairs;
            }
        }
    }
    cout << pairs;
    return 0;

/*n = int(input())
#A = [int(x) for x in input().split()]
A.append(0)
maxi = sum(A)

mini = 0
ind = 0
while ind<n+1:
    while ind<n+1 and A[ind]==0:
        ind+=1
    if ind==n+1:
        break
    ind += 2
    mini+=1
print mini,maxi*/
}
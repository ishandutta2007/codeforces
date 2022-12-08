#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int max1=0,max2=0,sum=0;
    vector <int> h,w;
    int n;
    cin >>n;
    h.resize(n);
    w.resize(n);
    for (int i=0; i<n; i++)
        {
            cin >>w[i] >>h[i];
            sum+=w[i];
            if (h[i]>max1)
            {
                max2=max1;
                max1=h[i];
            }
            else if (max2<h[i]) max2=h[i];
        }
    for (int i=0; i<n; i++)
        if (h[i]==max1) cout <<max2*(sum-w[i]) <<' ';
        else cout <<max1*(sum-w[i]) <<' ';
    return 0;
}
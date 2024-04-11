#include <bits/stdc++.h>

using namespace std;
long long maxx=pow(10,18);
int moduo=1000000007;
int main()
{
    vector<long long> stepeni;
    long long tr=1;
    stepeni.push_back(1);
    while(tr<=maxx)
    {
        tr=tr*(long long)2;
        stepeni.push_back(tr);
        //printf("%lld\n",tr);
    }
    long long x,k;
    cin >> x >> k;
    long long xx=k+1;
    vector<int> step;
    while(k>0)
    {
        int i=0;
        while(stepeni[i]<=k)
        {
            i++;
        }
        i--;
        step.push_back(i);
        k-=stepeni[i];
    }
    vector<int> step2;
    while(xx>0)
    {
        int i=0;
        while(stepeni[i]<=xx)
        {
            i++;
        }
        i--;
        step2.push_back(i);
        xx-=stepeni[i];
    }
    long long vred=2;
    int tren=0;
    long long ss1=1,ss2=1;
    for(int i=step.size()-1;i>=0;i--)
    {
        while(tren<step[i])
        {
            tren++;
            vred=(vred*vred)%moduo;
        }
        ss2=(ss2*vred)%moduo;
    }
    vred=2;
    tren=0;
    for(int i=step2.size()-1;i>=0;i--)
    {
        while(tren<step2[i])
        {
            tren++;
            vred=(vred*vred)%moduo;
        }
        ss1=(ss1*vred)%moduo;
    }
    if(x==0)
    {
        cout << 0 << endl;
        return 0;
    }
    x=x%moduo;
    k=k%moduo;
    long long res=(x*ss1)%moduo;
    res=(res-ss2+moduo+1)%moduo;
    cout << res << endl;
    return 0;
}
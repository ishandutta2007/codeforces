#include <iostream>
using namespace std;

int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    int answer = a+b;
    int counter =0;
    
    for(int i=0;i<n;i++)
    {
        char c;
        cin>>c;
        if(c=='.')
            counter++;
        else
        {
            int max = (counter+1)/2;
            int min = counter-max;
            if(a>b)
            {
                a-=max;
                b-=min;
            }
            else
            {
                a-=min;
                b-=max;
            }
            counter=0;
        }
    }
    int max = (counter+1)/2;
    int min = counter-max;
    if(a>b)
    {
        a-=max;
        b-=min;
    }
    else
    {
        a-=min;
        b-=max;
    }
    counter=0;
    if(a>0)
        answer-=a;
    if(b>0)
        answer-=b;
        
    cout<<answer<<endl;
    return 0;
}
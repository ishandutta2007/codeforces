#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, v;
    int result=0;
    cin>>n>>v;
    vector <int> list;
    for(int i=0; i<n; i++)
    {
        int k;
        cin>>k;
        bool x=true;
        for(int j=0; j<k; j++)
        {
            int s;
            cin>>s;
            if(x && s<v)
            {
                result++;
                x=false;
                list.push_back(i+1);
            }
        }
    }
    cout<<result<<endl;
    if(result>0)
    {
        for(int i=0; i<list.size(); i++)
            cout<<list[i]<<' ';
    }
    return 0;
}
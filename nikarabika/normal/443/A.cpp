#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector <char> b;
    for(int i=0; 1; i++)
    {
        char a;
        cin>>a;
        if(a=='}')
            break;
        if(a!='{' && a!='}' && a!=',' && a!=32)
        {
            bool k=true;
            for(int j=0; j<b.size(); j++)
            {
                if(b[j]==a)
                {
                    k=false;
                }
            }
            if(k)
                b.push_back(a);
        }
    }
    cout<<b.size()<<endl;
    return 0;
}
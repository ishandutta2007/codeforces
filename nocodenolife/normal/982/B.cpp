#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <iterator>

using namespace std;


int main() {
    int n;
    cin>>n;
    vector <int> extro;
    map <int, int> intro;
    
    for(int i=1;i<=n;i++)
    {
        int width;
        cin>>width;
        intro.insert(pair<int, int>(width, i));
    }
    
    map <int, int> :: iterator itr;
    itr = intro.begin();
    for(int i=0;i<2*n;i++)
    {
        char c;
        cin>>c;
        if(c=='0')
        {
            int seat = itr->second;
            cout<<seat<<" ";
            extro.push_back(seat);
            itr++;
        }
        else
        {
            int seat = extro.back();
            extro.pop_back();
            cout<<seat<<" ";
        }
    }
    return 0;
}
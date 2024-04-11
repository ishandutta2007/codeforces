#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <deque>
#include <map>
#include <vector>
#include <stack>
using namespace std;

stack <int> mixing;
int carrots=2,calories=0,chocolate=100,flour=1,egg=1;
int tmp;
int i;

int main()
{
    mixing.push(0);
    cin >> carrots;
    for (i=1;i<=carrots;++i)
    {
        cin >> tmp;
        calories+=tmp*i;
    }
    cout << calories << endl;
}
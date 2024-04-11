#include <iostream>

using namespace std;

int main()
{
    int houses,love,cash;
    cin >> houses >> love >> cash;
    int distance = 10000;
    love--;
    int cost;
    for(int i = 0;i<houses;i++){
        cin >> cost;
        if(cost <= cash && cost != 0){
            if(distance > (max(i,love) - min(i,love)) * 10){
                distance = (max(i,love) - min(i,love)) * 10;
            }
        }
    }



    cout << distance;
    return 0;
}
#include <iostream>
#include <unordered_set>

using namespace std;

int f(int n)
{
    n++;
    while (n % 10 == 0)
    {
        n /= 10;
    }
    return n;
}

int main()
{
    int n;
    cin >> n;
    unordered_set<int> nums;
    nums.insert(n);
    n = f(n);
    while (nums.find(n) == nums.end())
    {
        nums.insert(n);
        n = f(n);
    }

    cout << nums.size();
    return 0;
}
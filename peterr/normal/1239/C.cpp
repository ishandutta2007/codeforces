#include <bits/stdc++.h>

using namespace std;

struct Event
{
    long long t;
    bool water;
    int index;
};

class cmp
{
public:
    bool operator()(Event a, Event b)
    {
        if (a.t != b.t)
            return a.t > b.t;
        if (a.water != b.water)
            return a.water;
        return a.index > b.index;
    }
};

const int MAXN = 100000;
int passengers[MAXN];
long long ans[MAXN];

int main()
{
    int n, p;
    cin >> n >> p;
    priority_queue<Event, vector<Event>, cmp> events;
    for (int i = 0; i < n; i++)
    {
        cin >> passengers[i];
        events.push({passengers[i], false, i});
    }
    queue<int> waterLine;
    priority_queue<int, vector<int>, greater<int>> ready;
    while (!events.empty())
    {
        Event e = events.top();
        events.pop();
        long long curTime = e.t;
        if (e.water)
        {
            waterLine.pop();
            ans[e.index] = e.t;
            if (!waterLine.empty())
            {
                events.push({curTime + p, true, waterLine.front()});
            }
            else if (!ready.empty())
            {
                waterLine.push(ready.top());
                events.push({curTime + p, true, ready.top()});
                ready.pop();
            }
        }
        else
        {
            ready.push(e.index);
            int person = ready.top();
            if (waterLine.empty())
            {
                waterLine.push(person);
                events.push({curTime + p, true, person});
                ready.pop();
            }
            else if (ready.top() < waterLine.back())
            {
                waterLine.push(person);
                ready.pop();
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    cout << endl;
    return 0;
}
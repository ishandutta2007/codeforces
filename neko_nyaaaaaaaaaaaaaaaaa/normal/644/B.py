import collections 
nb = list(map(int, input().split()))

n = nb[0]
b = nb[1]
queries = collections.deque()
for i in range(n):
  td = list(map(int, input().split()))
  queries.append((td[0], td[1], i))

answer = [0] * n
processed = []
# answer[0] = processed[-1][-1]
queue = collections.deque()

next_available = 0
i = 0
cnt = 0
# significant events: a process "requests" to join queue, a process gets out of queue and is processed
while cnt != n:
  # we are at cur_time
  # event: process joins queue --> may or may not happen
  # event: starts process
  # event: end process
  # at each event: there are two works to do
  # 1. eject one process in queue
  # 2. accept/reject any "queue join requests"
  
  # if queue is empty:
  #   fast forward to next process
  #   put that process into queue
  #     reasoning: queue is currently empty, we don't lose anything if we just put process into queue
  #                it gets popped out immediately later anyway
  #   continue
  # else queue is not empty:
  #   pop first process --> fast forward until done process
  #   admit any process requesting to join queue:
  #     while (next_process.time <= cur_time): admit into queue if possible
  if not queue:
    start, cost, i = queries.popleft()
    queue.append((start, cost, i))
    continue
  else:
    first_in_line_start, first_in_line_cost, cur_i = queue.popleft()
    next_available =  max(next_available, first_in_line_start) + first_in_line_cost
    answer[cur_i] = next_available
    #print(cur_i)
    #print(next_available)
    #print(queue)
    #print(queries)
    cnt += 1
    while queries and queries[0][0] < next_available:
      if len(queue) >= b:
        f1, f2, cur_i = queries.popleft()
        answer[cur_i] = -1
        cnt += 1
      else:
        queue.append(queries.popleft())
print(*answer)
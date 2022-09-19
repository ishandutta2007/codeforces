ar = [[3,3,-1,4,4,-1,3,3],
      [3,3,-1,4,4,-1,3,3],
      [2,2,-1,3,3,-1,2,2],
      [2,2,-1,3,3,-1,2,2],
      [1,1,-1,2,2,-1,1,1],
      [1,1,-1,2,2,-1,1,1]]
ar2 = ["","","","","",""]
for i in 0..5
  ar2[i] = gets
end
x = 0
y = 0
cur = -1
for i in 0..5 do
  for j in 0..7 do
    if ar2[i][j] == '.' && ar[i][j]>cur then
      cur = ar[i][j]
      x = i
      y = j
    end
  end
end
ar2[x][y] = 'P'
for i in 0..5 do
  puts ar2[i]
end
# ar2 = [4,3,2,1]
# for j in ar 2 do
#   puts j
# end
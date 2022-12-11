n = gets.strip.to_i
data = gets.split.map(&:to_i).sort

dis = (0..n-2).map { |i| data[i+1] - data[i] }
ans = dis.min
print "#{ans} #{dis.select { |v| v == ans }.length}\n"
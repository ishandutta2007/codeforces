n, k = gets.split.map(&:to_i)
a = gets.split.map(&:to_i)

status = (1..n).to_a
leader = 0
a.each { |step|
    eliminate = (leader + step) % status.length
    print "#{status[eliminate]} "
    status = status.select.with_index { |v, i| i != eliminate }
    leader = eliminate
}
print "\n"
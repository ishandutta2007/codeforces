tux=gets
foo=0
bar=0
baz=0
quz=1
tux=tux.to_i
while tux>0
  tux-=1
  pur=gets
  pur=pur.to_i
  foo=foo+pur
  bar=bar+1
  if [foo * quz, bar*baz].max == foo*quz then
    baz=foo
    quz=bar
  end
end
puts 1.0*baz/quz
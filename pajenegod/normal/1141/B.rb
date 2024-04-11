gets
r=(gets*2).tr(' 
','').split(?0).map(&:size).max
p r==nil ?0:r
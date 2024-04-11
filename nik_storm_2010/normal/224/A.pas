uses math;
var
    pred,s1,s2,s3,x,y:longint;


begin

  readln(s1,s2,s3); pred:=max(s1,s2); pred:=max(pred,s3);
  for x:=1 to pred do
    for y:=1 to pred do
      begin
        if (x*y=s1) and (s2 mod x=0) and (s3 mod y=0) and (s2 div x=s3 div y)
          then
          begin
            writeln((x+y+s2 div x)*4);
            halt;
          end;
      end;

end.
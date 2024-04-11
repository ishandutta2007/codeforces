uses math;
var
    leng,fuel:array[1..1000] of longint; tekfuel,pred,time,m,k,i:longint;


begin

  readln(m,k); for i:=1 to m do read(leng[i]);
  readln; for i:=1 to m do read(fuel[i]);
  time:=0; tekfuel:=0; pred:=0;
  for i:=1 to m do
    begin
      tekfuel:=tekfuel+fuel[i]; pred:=max(pred,fuel[i]);
      while tekfuel<leng[i] do
        begin
          tekfuel:=tekfuel+pred;
          time:=time+k;
        end;
      tekfuel:=tekfuel-leng[i]; time:=time+leng[i];
    end;
  writeln(time);

end.
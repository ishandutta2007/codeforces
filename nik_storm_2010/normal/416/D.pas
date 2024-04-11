const
  oo=round(1e18);
var
  step,last,ans,ind,n,x,elm:int64;
  i:longint;

procedure push(x,i:int64);
var
  need,all:int64;
begin
  if (x=-1) then
  begin
    if (step=oo) then inc(elm) else
    begin
      x:=last+step;
      if (x<=0) then
      begin
        step:=oo;
        last:=-1;
        elm:=1;
        ind:=-1;
        inc(ans);
      end
      else
      begin
        inc(elm);
        last:=x;
        ind:=i;
      end;
    end;
  end
  else
  begin
    if (step=oo) then
    begin
      if (last=-1) then
      begin
        last:=x;
        ind:=i;
        inc(elm);
      end
      else
      begin
        need:=x-last;
        all:=i-ind;
        if (need mod all<>0) then
        begin
          step:=oo;
          last:=x;
          elm:=1;
          ind:=i;
          inc(ans);
        end
        else
        begin
          step:=need div all;
          last:=x;
          ind:=i;
          if (step>0) and (x-elm*step<=0) then
          begin
            step:=oo;
            last:=x;
            elm:=1;
            ind:=i;
            inc(ans);
          end
          else inc(elm);
        end;
      end;
    end
    else
    begin
      need:=last+step;
      if (x<>need) then
      begin
        step:=oo;
        last:=x;
        elm:=1;
        ind:=i;
        inc(ans);
      end
      else
      begin
        inc(elm);
        last:=x;
        ind:=i;
      end;
    end;
  end;
end;

begin
  step:=oo;
  last:=-1;
  ind:=-1;
  ans:=1;
  elm:=0;
  readln(n);
  for i:=1 to n do
  begin
    read(x);
    push(x,i);
  end;
  writeln(ans);
end.
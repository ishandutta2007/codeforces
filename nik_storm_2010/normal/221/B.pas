var
    all:array[0..9] of boolean; priz:boolean;
      ans,xx,x,q,i,c:longint;


begin

  readln(x); xx:=x;
  while xx<>0 do
    begin
      all[xx mod 10]:=true;
      xx:=xx div 10;
    end;

  q:=round(sqrt(x)); ans:=0;
  for i:=1 to q do
    if x mod i = 0 then
      begin
        c:=i; priz:=false;
        while c<>0 do
          begin
            if all[c mod 10]=true then begin priz:=true; break; end;
            c:=c div 10;
          end;
        if priz=true then inc(ans);

        if x div i <> i then
          begin
            c:=x div i; priz:=false;
            while c<>0 do
              begin
                if all[c mod 10]=true then begin priz:=true; break; end;
                c:=c div 10;
              end;
            if priz=true then inc(ans);
          end;
      end;
  writeln(ans);

end.
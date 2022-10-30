const mas:array[1..2,1..4] of longint = ((+1,0,-1,0),(0,+1,0,-1));
var
    used:array[-100..100,-100..100] of boolean; answer,dir,i,j,x,y:longint;


begin

  readln(x,y); if (x=0) and (y=0) then begin writeln(0); halt; end;
  answer:=0; i:=0; j:=0; dir:=1; used[0,0]:=true;
  while true do
    begin
      i:=i+mas[1,dir]; j:=j+mas[2,dir]; used[i,j]:=true;
      if (x=i) and (y=j) then begin writeln(answer); halt; end;
      if (dir=1) and (used[i+mas[1,2],j+mas[2,2]]=false) then begin inc(answer); dir:=2; end else
      if (dir=2) and (used[i+mas[1,3],j+mas[2,3]]=false) then begin inc(answer); dir:=3; end else
      if (dir=3) and (used[i+mas[1,4],j+mas[2,4]]=false) then begin inc(answer); dir:=4; end else
      if (dir=4) and (used[i+mas[1,1],j+mas[2,1]]=false) then begin inc(answer); dir:=1; end;
    end;

end.
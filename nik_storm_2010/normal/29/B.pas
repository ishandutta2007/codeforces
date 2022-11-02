var
 l,d,v,g,r,start:longint;
  time:extended;
   tek:string;


begin

  readln(l,d,v,g,r);
   time:=d/v;

  start:=0;
   tek:='green';
    while true do
     begin
      if tek='green'
       then
        begin
         if start+g>time
          then
           begin
            break;
           end
          else
           begin
            start:=start+g;
             tek:='red';
           end;
        end
       else
        begin
         if start+r>time
          then
           begin
            start:=start+r;
             time:=start;
            break;
           end
          else
           begin
            start:=start+r;
             tek:='green';
           end;
        end;
     end;
   time:=time + (l-d)/v;
  writeln(time:0:6);

end.
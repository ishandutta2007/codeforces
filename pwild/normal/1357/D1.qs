namespace Solution {
    open Microsoft.Quantum.Intrinsic;
    open Microsoft.Quantum.MachineLearning;

    operation Solve () : ((Int, Double[]), ControlledRotation[], (Double[], Double)) {
        return ((1, [1.0,1.0]), 
                [
					ControlledRotation((0, new Int[0]), PauliX, 4),
					ControlledRotation((0, new Int[0]), PauliZ, 5),
					ControlledRotation((1, new Int[0]), PauliX, 6),
					ControlledRotation((1, new Int[0]), PauliZ, 7),
					ControlledRotation((0, [1]), PauliX, 0),
					ControlledRotation((1, [0]), PauliX, 1),
					ControlledRotation((1, new Int[0]), PauliZ, 2),
            		ControlledRotation((1, new Int[0]), PauliX, 3)
        		],
                ([2.3900306246158234, 1.6562188160856888, 4.372553709762874, 3.847379844438077, 2.9756725595602775, 4.802926183087957, 3.9242370461576965, 2.0676881639589166], -0.20439999999999997));
    }
}